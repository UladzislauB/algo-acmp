#include <iostream>
#include <stack>
typedef unsigned int uint;
bool is_beg_end(int a, int b);
bool is_expr(const char* s, uint& pos);
 
int main(){
    uint p;
    char s1[200];
    std::cin >> s1;
    if(is_expr(s1, p))
        std::cout << 1;
    else
        std::cout << 0;
 
    return 0;
}
 
struct binfo {
    int  ch;
    uint pos;
    binfo(void){}
    binfo(int c, uint p):ch(c), pos(p){}
};
 
bool is_expr(const char* s, uint& p){
    const char* t = s;
    std::stack<binfo> st;
 
    for(; *s; ++s){
        switch(*s){
        case '(':
            st.push(binfo(*s, static_cast<uint>(s - t)));
            break;
        case ')':
            if(st.empty() || !is_beg_end(st.top().ch, *s)){
                p = static_cast<uint>(s - t);
                return false;
            }
            st.pop();
            break;
        }
    }
 
    bool ret = st.empty();
    for(; !st.empty(); st.pop())
        p = st.top().pos;
    return !*s && ret;
}
 
bool is_beg_end(int a, int b){
    return a == '(' && b == ')';
}