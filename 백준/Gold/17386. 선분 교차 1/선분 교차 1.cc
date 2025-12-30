#include <iostream>
#include <vector>

#define ll long long
#define pll pair<ll, ll>
using namespace std;

// 1 -> 양수, -1 -> 음수
int get_cross_prod_z(pll p1, pll p2, pll p3, pll p4) {
    pll a = {p2.first-p1.first, p2.second-p1.second};
    pll b = {p4.first-p3.first, p4.second-p3.second};
    return (a.first*b.second - a.second*b.first) > 0 ? 1 : -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x, y;
    cin >> x >> y;
    pll p1 = {x, y};
    cin >> x >> y;
    pll p2 = {x, y};
    cin >> x >> y;
    pll p3 = {x, y};
    cin >> x >> y;
    pll p4 = {x, y};
    
    // (p1, p2)와 (p1, p3) 및 (p1, p4) 외적의 z값의 부호가 반대
    int z1 = get_cross_prod_z(p1, p2, p1, p3);
    int z2 = get_cross_prod_z(p1, p2, p1, p4);

    bool flag1 = z1*z2 < 0 ? true : false;

    // (p3, p4)와 (p3, p1) 및 (p3, p2) 외적의 z값의 부호가 반대
    int z3 = get_cross_prod_z(p3, p4, p3, p1);
    int z4 = get_cross_prod_z(p3, p4, p3, p2);

    bool flag2 = z3*z4 < 0 ? true : false;

    // cout << z1 << '\n';
    // cout << z2 << '\n';
    // cout << z3 << '\n';
    // cout << z4 << '\n';

    cout << (flag1 && flag2) ? 1 : 0;
    return 0;
}