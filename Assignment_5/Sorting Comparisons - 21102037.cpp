#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

// Time Complexity- O(n^2).
pair<int,int> SelectionSort(int *input,int size)
{
    int min_idx;
    int count_swaps = 0;
    int count_comparisons = 0;
    for(int i=0;i<size;i++)
    {
        min_idx = i;
        for(int j=i+1;j<size;j++)
        {
            if(input[j]<input[min_idx])
            {
                min_idx = j;
                count_swaps++;
            }
            count_comparisons++;
        }
        int temp = input[i];
        input[i] = input[min_idx];
        input[min_idx] = temp;
    }
    return {count_swaps, count_comparisons};
}


// Time Complexity- O(n^2).
pair<int,int> bubbleSort(int *input, int size)
{
    int count_swaps = 0;
    int count_comparisons = 0;
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - 1 - j; i++)
        {
            if (input[i] > input[i + 1])
            {
                int temp = input[i];
                input[i] = input[i + 1];
                input[i + 1] = temp;
                count_swaps++;
            }
            count_comparisons++;
        }
    }
    return {count_swaps, count_comparisons}; 
}


// Time-run calculator
long getTimeinMicroseconds(){
    struct timeval start;
    gettimeofday(&start, NULL);
    return start.tv_sec * 1000000 + start.tv_usec;
}


int main()
{
    int n;
    cout << "Enter array_size : ";
    cin >> n;

    cout<< "Enter array elements : ";
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
   
    pair <int,int> bubble = bubbleSort(arr,n);
    pair <int,int> selection = SelectionSort(arr,n);

    cout << "Comparing bubble and selection sort:" << endl;
    cout << endl;

    cout << "1) On the basis of number of comparisions:" << " ";
    if(bubble.second > selection.second)
    {
        cout << "Bubble sort requires more comparisions." << endl;
    }
    else if(bubble.second < selection.second)
    {
        cout << "Selection sort requires more comparisions." << endl;
    }
    else
    {
        cout << "Equal number of comparisions." << endl;
    }
    cout << endl;

    cout << "2) On the basis of Number of swaps:" << " ";
    if(bubble.first > selection.first)
    {
        cout << "Bubble sort requires more swaps." << endl;
    }
    else if(bubble.first < selection.first)
    {
        cout << "Selection sort requires more sorts." << endl;
    }
    else
    {
        cout << "Equal number of swaps." << endl;
    }

    cout<<endl;
    cout<< "3) On the basis of runtime:"<<endl;
    for (int n=10; n<=10000; n*=10){
        int *arr = new int[n];
        long start_time, end_time;
        for(int i=0; i<n; i++) {
            arr[i] = n-i;
        }
        // Bubble sort complexity
        start_time = getTimeinMicroseconds();
        bubble = bubbleSort(arr,n);
        end_time = getTimeinMicroseconds();
        cout<<"BubbleSort for n = "<<n<<" time = "<<end_time-start_time<<" nanoseconds."<<endl;

        // Selection sort complexity
        start_time = getTimeinMicroseconds();
        selection = SelectionSort(arr,n);
        end_time = getTimeinMicroseconds();
        cout<<"SelectionSort for n = "<<n<<" time = "<<end_time-start_time <<" nanoseconds." <<endl;
        cout<<endl;
        
    }   
    cout<<"Clearly Selection sort is faster than Bubble sort for large sized array."<<endl;

}
