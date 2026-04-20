#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> parseCSVLine(const string& line) {
    vector<string> result;
    string current_cell = "";
    bool in_quotes = false;
    
    for (size_t i = 0; i < line.length(); ++i) {
        char c = line[i];
        if (c == '"') {
            in_quotes = !in_quotes;
        } else if (c == ',' && !in_quotes) {
            result.push_back(current_cell);
            current_cell = "";
        } else {
            current_cell += c;
        }
    }
    result.push_back(current_cell);
    return result;
}

int getColumnIndex(const vector<string>& headers, const string& target) {
    for (size_t i = 0; i < headers.size(); ++i) {
        if (headers[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    string filename = "http_data.csv";
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    string line;
    if (!getline(file, line)) {
        cerr << "Error: File is empty." << endl;
        return 1;
    }

    vector<string> headers = parseCSVLine(line);
    
    int idx_no = getColumnIndex(headers, "No.");
    int idx_src_ip = getColumnIndex(headers, "Source");
    int idx_dst_ip = getColumnIndex(headers, "Destination");
    int idx_protocol = getColumnIndex(headers, "Protocol");
    int idx_info = getColumnIndex(headers, "Info");
    
    int idx_src_port = getColumnIndex(headers, "Source Port");
    if (idx_src_port == -1) idx_src_port = getColumnIndex(headers, "Src Port");
    
    int idx_dst_port = getColumnIndex(headers, "Destination Port");
    if (idx_dst_port == -1) idx_dst_port = getColumnIndex(headers, "Dst Port");

    cout << "Wireshark HTTP Packet Analysis \n";

    while (getline(file, line)) {
        if (line.empty() || line == "\r") continue; 

        vector<string> row = parseCSVLine(line);
        
        if (row.size() < headers.size()) continue;

        string protocol = (idx_protocol != -1) ? row[idx_protocol] : "";
        string packet_no = (idx_no != -1) ? row[idx_no] : "N/A";
        string src_ip = (idx_src_ip != -1) ? row[idx_src_ip] : "N/A";
        string dst_ip = (idx_dst_ip != -1) ? row[idx_dst_ip] : "N/A";
        string src_port = (idx_src_port != -1) ? row[idx_src_port] : "N/A";
        string dst_port = (idx_dst_port != -1) ? row[idx_dst_port] : "N/A";
        string info = (idx_info != -1) ? row[idx_info] : "N/A";

        cout << "Packet No: " << packet_no << "\n";
        cout << "1. Source IP: " << src_ip << " -> Destination IP: " << dst_ip << "\n";
        cout << "2. Source Port: " << src_port << " -> Destination Port: " << dst_port << "\n";
        
        if (protocol == "HTTP" || protocol == "HTTP/XML") {
            cout << "3. HTTP Message: " << info << "\n";
        }
    }

    file.close();
    return 0;
}