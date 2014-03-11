#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <fstream>
#include <sstream>
using namespace std;

class TextQuery {
    public:
        TextQuery(const string &str): file(str) {}
        void read_file();
        void search_word(const string &); 
    private:
        const string file;
        map<string, int> word_counts;
        map<string, set<int> > dict;
};

void TextQuery::read_file() {
    string line, word;
    ifstream ifile(file.c_str());

    int line_num = 0;
    while (getline(ifile, line)) {
        line_num++;
        stringstream strm(line);
        while (strm >> word) {
            word_counts[word]++;
            dict[word].insert(line_num);
            }
    }

    ifile.close();
}

void TextQuery::search_word(const string &word) {
    cout << word_counts[word] << endl;
    set<int>::iterator st = dict[word].begin(), ed = dict[word].end();
    while (st != ed) {
        cout << *st << endl;
        st++;
    }
}

int main(int argc, char* argv[]) {
    char *file = argv[1];
    TextQuery tq(file);
    tq.read_file();

    string s;
    
    cout << "input one word" << endl;
    while (cin >> s) {
        tq.search_word(s);
        cout << "input one word" << endl;
    }

    return 0;
}
