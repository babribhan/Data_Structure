// Merge Sort Time complexity is O(N.log N) in all three cases.
//           { O(1)           if n <= 1
//   T(n)  = | 2T(n/2) + cn   otherwise
//           {
void merge (vector<int> &arr, int start , int mid, int end )
{
        int i , j , k;
        int n1 = mid - start+1;
        int n2 = end - mid;
        int left[n1];
        int right[n2];
        for ( int i = 0; i < n1 ; i++ )
                left[i] = arr[start+i];

        for ( int j = 0; j < n2 ; j++ )
                right[j] = arr[mid+1+j];

        i = j = 0;
        k = start;
        while ( i < n1 && j < n2 ) 
        {
                //if ( left[i] <= right[j] )
                if ( left[i] > right[j] )
                        arr[k++] = left[i++];
                else 
                        arr[k++] = right[j++];
        }
        while ( i < n1 ) 
                arr[k++] = left[i++];
        while ( j < n2 ) 
                arr[k++] = right[j++];
}

void merge_sort (vector<int> &arr, int start , int end ) 
{
        if ( start < end ) 
        {
                int mid = (start + (end - start )/2 ) ;
                merge_sort (arr,start,mid);
                merge_sort (arr,mid+1,end);
                merge (arr,start,mid,end);
        }
}
