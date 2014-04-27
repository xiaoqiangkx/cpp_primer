namespace cplusplus_primer {
    namespace MatrixLib {
        class matrix {};
        matrix operator* (const matrix &, const matrix &);
    };
};

cplusplus_primer::MatrixLib::matrix cplusplus_primer::MatrixLib::operator* (
    const matrix &, const matrix &);    /* 由于operator* 已经定义了作用域, 所以参数列表中matrix无需在定义 */

int main() {
    return 0;
}
