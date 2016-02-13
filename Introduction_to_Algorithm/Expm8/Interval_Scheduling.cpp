#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

class WeightedInterval {
public:
    int start, finish, weight;

    bool operator < (const WeightedInterval& x) const   {
        if (finish != x.finish)
            return finish < x.finish;
        return start < x.start;
    }
} *weightedIntervals;


class Interval {
public:
    int start, finish;

    bool operator < (const Interval& x) const   {
        if (finish != x.finish)
            return finish < x.finish;
        return start < x.start;
    }
} *intervals;

void greedyIntervalSchedule(int* start, int* finish, const int n, queue<int> &opt);
void DPIntervalSchedule(int* start, int* finish, int* weight, const int n, stack<int> &opt);

int main()
{
	int n = 5;
	int start[n] = {1,2,4,6,8};
	int finish[n] = {3,5,7,9,10};
	int weight[n] = {1,1,1,1,1};
	queue<int> opt1;
	greedyIntervalSchedule(start, finish, n, opt1);
	
	cout << "--------------Greedy Interval Scheduling--------------" << endl;
	cout << "Number of selected jobs: " << opt1.size() << endl;
	cout << "Job  " << "start  " << "finish" << endl;
    while(!opt1.empty())
	{
        int i = opt1.front();
        opt1.pop();
        cout << i << "\t" << intervals[i].start << "\t" << intervals[i].finish << endl;
    }
	cout << endl;
	
	stack<int> opt2;
	DPIntervalSchedule(start, finish, weight, n, opt2);
	cout << "--------------DP Interval Scheduling--------------" << endl;
	cout << "Number of selected jobs: " << opt2.size() << endl;
	cout << "Job  " << "start  " << "finish  "  << "weight  " << endl;
    while(!opt2.empty())
	{
        int i = opt2.top();
        opt2.pop();
        cout << i-1 << "\t" << weightedIntervals[i-1].start << "\t" <<  weightedIntervals[i-1].finish 
			<< "\t" << weightedIntervals[i-1].weight << endl;
    }
}

// returns index of the interval having greatest finish time <= value in range [low, high]
int binary_search(int low, int high, int value)
{
    int mid;
    while (low < high) 
	{
        mid = low + (high - low + 1) / 2;
        if(weightedIntervals[mid].finish <= value)
            low = mid;
        else
            high = mid - 1;
    }
    if (weightedIntervals[low].finish > value)
        return 0;
    return low;
}

// returns index of the interval having greatest finish time <= start time of interval i
int greatestNonOverlappingInterval(int i)
{
    return binary_search(0, i - 1, weightedIntervals[i].start);
}

void greedyIntervalSchedule(int* start, int* finish, const int n, queue<int> &opt)
{
    int i, last_finished;
    intervals = new Interval[n];
    for(i = 0; i < n; i++)
	{
		intervals[i].start = start[i];
		intervals[i].finish = finish[i];
	}
    // sort intervals in non-decreasing order of finish times
    sort(intervals, intervals + n);
    // construct the optimal solution
    for(i = 0, last_finished = 0; i < n; i++)
	{
        if (intervals[i].start >= last_finished) 
		{
            opt.push(i);
            last_finished = intervals[i].finish;
        }
	}
}

void DPIntervalSchedule(int* start, int* finish, int* weight, const int n, stack<int> &opt)
{
	int i, *dp, *p;
    weightedIntervals = new WeightedInterval[n + 1];
    for(i = 1; i <= n; i++)
	{
        weightedIntervals[i].start = start[i];
		weightedIntervals[i].finish = finish[i];
		weightedIntervals[i].weight = weight[i];
	}
    // dummy interval used as a sentinel
    weightedIntervals[0].start = weightedIntervals[0].finish = weightedIntervals[0].weight = 0;
    // sort intervals in non-decreasing order of finish times
    sort(weightedIntervals + 1, weightedIntervals + n + 1);

    dp = new int[n + 1];
    p = new int[n + 1];
    dp[0] = p[0] = 0;

    // construct the value of the optimal solution
    for(i = 1; i <= n; i++)
	{
        p[i] = greatestNonOverlappingInterval(i);
        dp[i] = max(weightedIntervals[i].weight + dp[p[i]], dp[i-1]);
    }

    // construct the optimal solution
    for(i = n; i > 0; )
	{
        if(weightedIntervals[i].weight + dp[p[i]] >= dp[i-1]) 
		{
            opt.push(i);
            i = p[i];
        } 
		else
            i--;
    }
}