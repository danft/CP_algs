#include <bits/stdc++.h>
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define rof(i,a,b) for(int (i)=(a);(i) >= (b); --(i))
#define INF 0x3f3f3f3f
#define mk make_pair
#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

struct Point{
	int x, y;
	Point( ) {}
	Point( int x0, int y0 ):x(x0), y(y0)
	{ }
	Point operator-( Point a ) {
		return Point( x-a.x, y-a.y );
	}
	int operator*( Point a ) {
		return x*a.x + y*a.y;
	}
	int operator^( Point a ) {
		return x*a.y - y*a.x;
	}
	double distance( Point a ) {
		return ( sqrt( (x-a.x)*(x-a.x) + (y-a.y)*(y-a.y) ) );
	}
	ll sqdistance( Point a ) {
		return ( ( 1LL*(x-a.x)*(x-a.x) + 1LL*(y-a.y)*(y-a.y) ) );
	}
};

struct Line {
	int a, b, c;
	Line() :a(0),b(0),c(0) {}
	Line( Point p0, Point p1 ) {
		a = p1.y-p0.y;
		b = p0.x-p1.x;
		c = a*p1.x + b*p1.y;
	}
	bool operator==( Line L ) {
		if( a > L.a )
		{
			return ( a*L.b == L.a*b && b*L.c == L.b*c && a*L.c == c*L.a);
		}
		else
			return ( L.a*b == a*L.b && L.b*c == b*L.c && L.a*c == L.c*a );
	}
	bool parallel( Line L ) {
		return (a*L.b - b*L.a == 0 );
	}
	bool intersect( Line L ) {
		return (a*L.b - b*L.a != 0 );
	}
	pair<double,double>intersection( Line L ) {
		if( intersect( L ) )
		{
			return pair<double,double>( double(c*L.b - b*L.c)/double(a*L.b-b*L.a),
					double(a*L.c - c*L.a)/double(a*L.b-b*L.a)
					);
		}
		else return pair<double,double>(0,0);
	}
};

int direction( Point p0, Point p1, Point p ) {
	return (p1-p0)^(p-p0);
}

bool on_segment( Point p0, Point p1, Point p ) {
	return ( min(p0.x,p1.x) <= p.x && max(p0.x,p1.x) >= p.x &&
			min(p0.y,p1.y) <= p.y && max(p0.y,p1.y) >= p.y );
}

bool seg_intersect( Point p0, Point p1, Point p2, Point p3 ) {
	int d[] = { direction( p0,p1,p2 ), direction( p0,p1,p3 ),
		direction( p2,p3, p0 ), direction( p2, p3, p1 ) };
	if( 1LL*d[0]*d[1] < 0LL && 1LL*d[2]*d[3] < 0LL )
		return true;
	if( d[0] == 0 && on_segment( p0, p1, p2 ) ) return true;
	if( d[1] == 0 && on_segment( p0, p1, p3 ) ) return true;
	if( d[2] == 0 && on_segment( p2, p3, p0 ) ) return true;
	if( d[3] == 0 && on_segment( p2, p3, p1 ) ) return true;
	return false;
}


int main(){
	return 0;
}
