#include <vector>
using namespace std;

template <typename T>
int getLen(const T& v) {
    // error: need ‘typename’ before ‘T:: size_type’ because ‘T’ is a dependent scope
    // 只会搜索数据成员, 而不搜索类型成员
    // T::size_type len = v.size();
    typename T::size_type len = v.size();
    return len;
}

int main() {
    int a = getLen(vector<int>(5, 0));
    return 0;
}
