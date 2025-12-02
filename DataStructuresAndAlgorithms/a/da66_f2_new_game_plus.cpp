#include <bits/stdc++.h>

using std::vector;
typedef long long ll;
typedef std::tuple<ll, ll, ll> tlll;

const ll mod = 1e8 + 7;

int main()
{
    int R, C;
    std::cin >> R >> C;

    vector<vector<bool>> rooms(R, vector<bool>(C));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            int x;
            std::cin >> x;
            rooms[i][j] = x;
        }

    std::vector<tlll> prevRoomCount(R);

    // fill up col 1 in prevRoomCount
    for (int room = 0; room < R; room++)
    {
        if (rooms[room][0] == true) continue;

        // going up
        if (room-1 >= 0 && rooms[room-1][1] == false)
            std::get<0>(prevRoomCount[room-1]) += 1;

        // going mid
        if (rooms[room][1] == false)
            std::get<1>(prevRoomCount[room]) += 1;

        // going down
        if (room+1 < R && rooms[room+1][1] == false)
            std::get<2>(prevRoomCount[room+1]) += 1;
    }

    // puts("fill passed");
    // for (auto a: prevRoomCount)
    // {
    //     std::cout << std::get<0>(a);
    //     std::cout << std::get<1>(a);
    //     std::cout << std::get<2>(a);
    //     std::cout << '\n';
    // }

    for (int currentCol = 2; currentCol < C; currentCol++)
    {
        std::vector<tlll> currentRoomCount(R);
        for (int room = 0; room < R; room++)
        {
            if (rooms[room][currentCol-1] == true) continue;
            tlll tup = prevRoomCount[room];
            ll up = std::get<0>(tup), mid = std::get<1>(tup), down=std::get<2>(tup);
            // std::cout << up << mid << down << '\n';

            // going up
            if (room-1 >= 0 && rooms[room-1][currentCol] == false)
            {
                std::get<0>(currentRoomCount[room-1]) += mid + down;
                std::get<0>(currentRoomCount[room-1]) %= mod;
            }

            // going mid
            if (rooms[room][currentCol] == false)
            {
                std::get<1>(currentRoomCount[room]) += up + down;
                std::get<2>(currentRoomCount[room]) %= mod;
            }

            // going down
            if (room+1 < R && rooms[room+1][currentCol] == false)
            {
                std::get<2>(currentRoomCount[room+1]) += up + mid;
                std::get<2>(currentRoomCount[room+1]) %= mod;
            }
        }

        std::swap(prevRoomCount, currentRoomCount); // prevent copy
    }

    ll total = 0;
    for (auto t: prevRoomCount)
    {
        total += std::get<0>(t);
        total += std::get<1>(t);
        total += std::get<2>(t);
        total %= mod;
    }

    // puts("asdfj");
    // for (auto a: prevRoomCount)
    // {
    //     std::cout << std::get<0>(a);
    //     std::cout << std::get<1>(a);
    //     std::cout << std::get<2>(a);
    //     std::cout << '\n';
    // }

    std::cout << total << '\n';
}
