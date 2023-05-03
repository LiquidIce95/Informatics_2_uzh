void print_pyra(int leftspace, int* arr, int rightspace, int size){

    for ( int k = 0; k < leftspace; k++){
        printf("%s"," ");
    }

    for (int k = 0; k < size ; k++){
        printf("%d", arr[k]);
    }

    for ( int k = 0; k < rightspace ; k++){
        printf("%s"," ");
    }



}

void sumup ( int * arr, int n){
    int arr2[n-1];


    for ( int k = 0; k < n-1; k++){
        arr2[k] = arr[k]+arr[k+1];
    }

    return arr2;
}


int main(){

    int n = 2;

    int arr[n];

    for ( int k = 0; k < n ; k++){
        arr[k] = k;
    }

    


    return 0;
}