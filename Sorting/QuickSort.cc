int get_pivot (vector<int> &arr, int start , int end ){
        int pivot = arr[end];
        int i = start-1;
        for ( int j = start ; j<end ; j++){
                //if ( arr[j] <= pivot ) {
                if ( arr[j] > pivot ) {
                        swap(arr[j],arr[++i]);
                }
        }
        swap(arr[i+1],arr[end]);
        return i+1;
}

void quick_sort (vector<int> &arr, int start , int end ) {
        if ( start < end ) {
                int p = get_pivot (arr,start,end);
                quick_sort (arr,start,p-1);
                quick_sort (arr,p+1,end);
        }
}
