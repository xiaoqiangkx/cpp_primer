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
        map<string, vector<int> > dict;
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
            if (dict[word].size() == 0) {
                dict[word].push_back(line_num);
            } else {
                size_t vec_size = dict[word].size();
                if (dict[word][vec_size - 1] != line_num) {
                    dict[word].push_back(line_num);
                }
            }
        } 
    }

    ifile.close();
}

void TextQuery::search_word(const string &word) {
    cout << word_counts[word] << endl;
    vector<int> &vec = dict[word];
    for (int i=0; i < vec.size(); i++) {
        cout << vec[i] << endl;
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
