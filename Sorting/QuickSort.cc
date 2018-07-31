int getPivot(vector<int> &arr, int start , int end ){
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

void quickSort(vector<int> &arr, int start , int end ) {
        if ( start < end ) {
                int p = getPivot(arr,start,end);
                quickSort(arr,start,p-1);
                quickSort(arr,p+1,end);
        }
}
