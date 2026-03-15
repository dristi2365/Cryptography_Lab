#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main() {
    string filename;
    int writeLimit;
    char fillChar;
    int n;

    for(n = 1; n <= 3; n++) {
        cout << "\n--- Input " << n << " ---" << endl;
        cout << "Enter filename (e.g. test.txt): ";
        cin >> filename;
        cout << "Enter fill character (e.g. X): ";
        cin >> fillChar;
        cout << "Enter write limit (e.g. 5000): ";
        cin >> writeLimit;

        ofstream file(filename.c_str(), ios::app);
        if(!file) {
            cout << "Error opening file!" << endl;
            continue;
        }

        string data(1000, fillChar);
        long long count = 0;

        cout << "WARNING: Malicious Logic Demonstration" << endl;
        cout << "Writing to " << filename << " continuously..." << endl;
        cout << "----------------------------------------------" << endl;

        while(true) {
            if(!file) {
                cout << "File write failed! Disk may be full." << endl;
                cout << "Program crashed after " << count << " writes." << endl;
                break;
            }
            file << data << "\n";
            count++;
            if(count % 1000 == 0) {
                cout << "Writes: " << count
                     << " | Approx size: " << (count * 1001) / 1024
                     << " KB written" << endl;
            }
            if(count == writeLimit) {
                cout << "Write limit reached! Stopping after "
                     << count << " writes." << endl;
                cout << "Approx size: " << (count * 1001) / 1024
                     << " KB written to " << filename << endl;
                break;
            }
        }
        file.close();
        cout << "Done! Remember to delete " << filename << " to free disk space." << endl;
    }

    cout << "\nName: Dristi Shakya | Roll No: 37 | Lab No: 16" << endl;
    return 0;
}
