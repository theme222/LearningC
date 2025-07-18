#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <ostream>
#include <queue>
#include <unordered_map>

typedef long long ll;
typedef std::unordered_map<ll, std::pair<ll,ll>> bigmap; // [row]: [left, right], lowestDist
typedef struct coords
{
    ll x;
    ll y;
    struct coords operator()(ll a, ll b)
    {
        struct coords c;
        c.x = a;
        c.y = b;
        return c;
    }
} coords;
typedef std::unordered_map<ll, std::unordered_set<ll>> coordset;

coordset visitedCoords;
bigmap chessBoard;
std::queue<std::pair<coords, ll>> checkNext;

bool CoordIsValid(coords coord)
{
    ll x = coord.x;
    ll y = coord.y;
    return chessBoard.contains(y) && chessBoard[y].first <= x && x <= chessBoard[y].second;
}

bool CoordIsVisited(coords coord)
{
    return visitedCoords.contains(coord.x) && visitedCoords[coord.x].contains(coord.y);
}

void AddCoordToVisisted(coords coord)
{
    if (!visitedCoords.contains(coord.x)) visitedCoords[coord.x] = std::unordered_set<ll>();
    visitedCoords[coord.x].insert(coord.y);
}

coords operator+(const coords& c1, const coords& c2)
{
    coords returnCoord = c1;
    returnCoord.x += c2.x;
    returnCoord.y += c2.y;
    return returnCoord;
}

std::ostream& operator<<(std::ostream& os, const coords& a)
{
    os << a.x << ", " << a.y;
    return os;
}


int main()
{
    coords start, end;
    scanf("%lld %lld %lld %lld", &start.y, &start.x, &end.y, &end.x);

    int segments;
    scanf("%d", &segments);

    while(segments--)
    {
        ll row, left, right;
        scanf("%lld %lld %lld", &row, &left, &right);
        if (chessBoard.contains(row))
        {
            chessBoard[row].first = std::min(chessBoard[row].first, left);
            chessBoard[row].second = std::max(chessBoard[row].second, right);
        }
        else
        {
            chessBoard[row] = std::pair<ll,ll>(left,right);
        }
    }

    // BFS
    checkNext.push(std::pair(start, -1));
    while (!checkNext.empty())
    {
        std::pair<coords,ll> current = checkNext.front();
        coords currentXY = current.first;
        ll currentLength = current.second+1;
        // std::cout << currentXY << " with dist " << currentLength << ' ' << CoordIsVisited(currentXY) <<'\n';
        checkNext.pop();
        if (CoordIsVisited(currentXY)) continue;
        AddCoordToVisisted(currentXY);
        if (currentXY.x == end.x && currentXY.y == end.y)
        {
            std::cout << currentLength << std::endl;
            exit(0);
        }

        coords up = currentXY + coords(0,1);
        if (CoordIsValid(up)) checkNext.push(std::pair(up, currentLength));

        coords down = currentXY + coords(0,-1);
        if (CoordIsValid(down)) checkNext.push(std::pair(down, currentLength));

        coords left = currentXY + coords(-1,0);
        if (CoordIsValid(left)) checkNext.push(std::pair(left, currentLength));

        coords right = currentXY + coords(1,0);
        if (CoordIsValid(right)) checkNext.push(std::pair(right, currentLength));

        coords upl = currentXY + coords(-1,1);
        if (CoordIsValid(upl)) checkNext.push(std::pair(upl, currentLength));

        coords upr = currentXY + coords(1,1);
        if (CoordIsValid(upr)) checkNext.push(std::pair(upr, currentLength));

        coords downl = currentXY + coords(-1,-1);
        if (CoordIsValid(downl)) checkNext.push(std::pair(downl, currentLength));

        coords downr = currentXY + coords(1,-1);
        if (CoordIsValid(downr)) checkNext.push(std::pair(downr, currentLength));
    }

    std::cout << -1 << std::endl;
}
