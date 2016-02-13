#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class MeetingRoom {
public:
    int index;
    int start;
    int end;
public:
    MeetingRoom(int i, int s, int e) : index(i), start(s), end(e) {}
};

bool isEndEarly(const MeetingRoom r1, const MeetingRoom r2) {
    return (r1.end < r2.end);
}

int main(int argc, char** argv)
{
    int tc, T;
    int num = 0;
    int count = 0;
    int index = 0;
    int start = 0;
    int end = 0;
    vector<MeetingRoom> rooms;

    freopen("input.txt", "r", stdin);
    cin >> T;
    for(tc = 0; tc < T; tc++)
    {
        rooms.clear(); // clear vector

        // get all the info of rooms
        cin >> num;
        for (int i = 0; i < num; i++) {
            cin >> index >> start >> end;
            MeetingRoom room(index, start, end);
            rooms.push_back(room);
        }

        // sort rooms for end time
        sort(rooms.begin(), rooms.end(), isEndEarly);

        // use greedy algorithm to solve promblem
        count = 1;
        MeetingRoom prev = rooms[0];
        for (vector<MeetingRoom>::iterator it = rooms.begin() + 1; it != rooms.end(); it++) {
            MeetingRoom current = *it;
            if (current.start >= prev.end) {
                count++;
                prev = current;
            }
        }

        cout << count << endl;
    }

    return 0;
}