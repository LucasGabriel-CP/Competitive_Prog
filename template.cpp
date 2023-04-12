/*
AGAIN
Fullmetal Alchemist
yume no tsuzuki oikaketeita hazu nano ni
magarikunetta hosoi michi hito ni tsumazuku
ano koro mitai nitte modoritai wake janai no
nakushite kita sora wo sagashiteru
 
wakatte kuremasu youni gisei ni natta youna
kanashii kao wa yamete yo
 
tsumi no saigo wa namida janai yo
zutto kurushiku seottekunda
deguchi mienai kanjou meiro ni
dare wo matteru no?
 
shiroi nooto ni tsuzutta youni
motto sunao ni hakidashitai yo
nani kara nogaretainda
 
genjitsu tte yatsu?
 
kanaeru tame ni ikiterundatte
wasurechai sou na yoru no manaka
bunan ni nante yatterarenai kara
kaeru basho mo nai no
 
kono omoi wo keshite shimau niwa
mada jinsei nagai desho (I'm on the way)
natsukashiku naru
konna itami mo kangei jan
 
ayamaranakucha ikenai yo ne ah, gomen ne
umaku ienakute shinpai kaketa mama datta ne
ano hi kakaeta zenbu ashita kakaeru zenbu
junban tsuketari wa shinaikara
 
wakatte kuremasu you ni sotto me wo tojitanda
mitakunaimono made miendamon
 
iranai uwasa ni chotto
hajimete kiku hatsugen docchi
nikai attara tomodachi datte uso wa yamete ne
 
akai haato ga iradatsu you ni
karadan naka moeteirunda
honto wa kitai shiten no
 
genjitsu tte yatsu?
 
kanaeru tame ni ikiterundatte sakebitaku naru yo kikoete imasu ka?
bunan ni nante yatterarenai kara
kaeru basho mo nai no
yasashisa niwa itsumo kansha shiteru dakara tsuyoku naritai
(I'm on the way)
susumu tame ni teki mo mikata mo kangei jan
 
dou yatte tsugi no doa akerundakke? kangaeteru?
mou hikikaesenai monogatari hajimatterunda
me wo samase
me wo samase
 
kono omoi wo keshite shimau niwa
mada jinsei nagai desho?
yarinokoshiteru koto
yarinaoshite mitai kara
mou ichido yukou
 
kanaeru tame ni ikiterundatte sakebitaku naru yo kikoete imasu ka?
bunan ni nante yatterarenai kara
kaeru basho mo nai no
yasashisa niwa itsumo kansha shiteru dakara tsuyoku naritai
(I'm on the way)
natsukashiku naru konna itami mo kangei jan
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

/*--------------------------------------------Compiler-Options-------------------------------------------------------------------------------------------------*/
//#pragma GCC optimize("O3")
//#pragma GCC optimize("unroll-loops")

#ifdef PIZZA
#define sleep(x) std::this_thread::sleep_for(std::chrono::milliseconds(x))
#define filIn std::freopen("input.txt", "r", stdin); //(__acrt_iob_func(0))
#define filOut std::freopen("output.txt", "w", stdout); //(__acrt_iob_func(1))
void dbg() { std::cerr << '\n'; }
template<typename X, typename...Y> void dbg(X x, Y...y) { std::cerr << ' ' << x; dbg(y...); }
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]: ", dbg(__VA_ARGS__), std::cerr << '\n'
#else
#define filIn void(0)
#define filOut void(0)
#define sleep(x) void(0)
#define debug(...) void(0)
#endif

/*-----------------------------------------------Defines-------------------------------------------------------------------------------------------------------*/
#define isvalid(a_, b_, n_, m_) (a_ >= 0 && a_ < n_ && b_ >= 0 && b_ < m_)
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define rforn(i, n) for (int i = (int)(n); i >= 0; --i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define rforr(i, l, r) for (int i = (int)(l); i >= (int)(r); --i)
#define fore(i, v) for (auto &i : v)
#define Mid (l + ((r - l) >> 1))
#define sz(var) ((int)(var).size())
#define all(var) (var).begin(),(var).end()

#define rand() uid(rng)
std::mt19937 rng(std::chrono::high_resolution_clock::now().time_since_epoch().count()); // ll = mt19937_64
std::uniform_int_distribution<int> uid(0, std::numeric_limits<int>::max());             // range

/*-----------------------------------------------Templates-----------------------------------------------------------------------------------------------------*/
template<class T>inline int lb(const std::vector<T>&v,const T&x,int l=0,int r=-1){return(int)(std::lower_bound(v.begin()+l,(r==-1?v.end():v.begin()+r),x)-v.begin());}
template<class T>inline int ub(const std::vector<T>&v,const T&x,int l=0,int r=-1){return(int)(std::upper_bound(v.begin()+l,(r==-1?v.end():v.begin()+r),x)-v.begin());}
template<class T>inline int lb(const T*v,int n,const T&x,int l=0,int r=-1){return(int)(std::lower_bound(v+l,v+(r==-1?n:r),x)-v);}
template<class T>inline int ub(const T*v,int n,const T&x,int l=0,int r=-1){return(int)(std::upper_bound(v+l,v+(r==-1?n:r),x)-v);}
template<class T,class T2>T min(T a,T2 b){return a<b?a:b;}
template<class T,class T2>T max(T a,T2 b){return a>b?a:b;}
template<class T,class ...T2>T min(T a,T2 ...b){return min(a,min(b...));}
template<class T,class ...T2>T max(T a,T2 ...b){return max(a,max(b...));}
template <typename T>
using min_heap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
using namespace __gnu_pbds;
template <class T>
using ordered_set = tree<T , null_type , std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using i64 = long long;
using d16 = long double;

/*-----------------------------------------------Constantes----------------------------------------------------------------------------------------------------*/
const int inf = (int)1e9, LGN = 20, maxn = (int)2e5 + 5, mod = 1000000007;
const i64 inf64 = (i64)4e18;
const double eps = 1e-9;

/*-----------------------------------------------Operadores----------------------------------------------------------------------------------------------------*/
template<class X, class Y> std::istream& operator >> (std::istream& input, std::pair<X, Y>& _var) { input >> _var.first >> _var.second; return input; }
template<class X> std::istream& operator >> (std::istream& input, std::vector<X>& _var) { for(X &x : _var) input >> x; return input; }
template<class X, class Y> std::ostream& operator << (std::ostream& output, std::pair<X, Y> const& _var) { output << _var.first << " " << _var.second; return output; }
template<class X> std::ostream& operator << (std::ostream& output, std::vector<X> const& _var) { for(int i = 0; i < sz(_var); i++) output << (i > 0 ? " " : "") << _var[i]; return output; }
template<class X, class Y> std::ostream& operator << (std::ostream& output, std::map<X, Y> const& _var) { bool first = 1; for(auto const &[a, b] : _var) { if(first == 0) output << " "; first = 0; output << "{" << a << " : " << b << "}"; } return output; }
template<class X> std::ostream& operator << (std::ostream& output, std::set<X> const& _var) { for(auto it = _var.begin(); it != _var.end(); it++) output << (it != _var.begin() ? " " : "") << *it; return output; }
template<class...X> inline void read(X &...x) { ((std::cin >> x), ...); }
template<class...X> inline void print(X const&...x) { ((std::cout << x), ...); }



int main(){
    std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);
    int tc = 1;
    std::cin >> tc;
    for (int Case = 1; Case <= tc; Case++){
        debug(Case);
        // solve();
        // std::cout << (solve() ? "Yes\n" : "No\n");
    }
    
    return 0;
}
