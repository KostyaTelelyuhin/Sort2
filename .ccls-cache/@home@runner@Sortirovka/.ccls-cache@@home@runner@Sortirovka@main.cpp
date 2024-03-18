#include <iostream>
using namespace std;


void swap1(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int* begin, int* end) {
    int pivot = *end;
    int* i = begin - 1;

    for (int* j = begin; j < end; j++) {
        if (*j < pivot) {
            i++;
            swap1(i, j);
        }
    }

    swap1(i + 1, end);
    return i + 1 - arr;
}

void quick_sort(int (&arr)[7], int* begin, int* end) {
    if (begin < end) {
        int partitionIndex = partition(arr, begin, end);

        quick_sort(arr, begin, arr + partitionIndex - 1);
        quick_sort(arr, arr + partitionIndex + 1, end);
    }
}


int bubble_sort(int (&a)[5])
{
  int N = 5;
  for (int final_ind = N - 1; final_ind >=0;final_ind--)
  {
    for(int i = 0; i < final_ind; i++) 
      {
        int j = i + 1;
        if(a[j] < a[i])
        {
          swap(a[i], a[j]);
        }
      }
  }
  return 0;
}

void sort_choose(int (&a)[5]){
  int N = 5;
  for (int i = 0; i < N - 1; i++)
  {
    int min_ind = i;
    for(int j = i + 1; j < N; j++)
    {
      if(a[j] < a[min_ind])
      {
        min_ind = j;
      }
    }swap(a[i], a[min_ind]);
  }
}

void sort_insert(int (&a)[])
{
  int N = 5;
  for (int i = 1; i < N; i++)
  {
    int j = i;
    for(int k = i - 1; k >= 0; k--)
    {
      if(a[j] < a[k]){
        swap(a[j], a[k]);
      }
    }
  }
}


void merger_sort(int (&arr)[7],int *begin, int *end)
{
  if(*begin == *end  - 1){
    return;
  }
  else
  {
    int N = *end - *begin;
    int mid = N / 2;
    
    
    int* begin_left_ptr = begin; 
    int end_left = *begin + mid;
    int* end_left_ptr = &end_left;  
    //cout << "begin_left_ptr: " << *begin_left_ptr << endl;
    //cout << "end_left_ptr: " << *end_left_ptr << endl;
    //cout << "sliceSize_l: " << sliceSize_l << endl;
    
    
    
    
    int begin_right = *begin + mid;
    int* begin_right_ptr = &begin_right; 
    int* end_right_ptr = end;  
    //cout << "begin_right_ptr: " << *begin_right_ptr << endl;
    //cout << "end_right_ptr: " << *end_right_ptr << endl;
    
    //cout << "sliceSize_r: " << sliceSize_r << endl;
    
    merger_sort(arr, begin_left_ptr, end_left_ptr);
    merger_sort(arr, begin_right_ptr, end_right_ptr);
    int Mass[1000];
    int l_ind = *begin_left_ptr;
    int r_ind = *begin_right_ptr;
    for(int i = *begin; i < *end;i++)
    {
      if (l_ind == *end_left_ptr)
      {
        Mass[i] = arr[r_ind];
        r_ind++;
      }
       else if (r_ind == *end_right_ptr)
      {
          Mass[i] = arr[l_ind];
          l_ind++;
      }
      else if(arr[l_ind] < arr[r_ind]){
        Mass[i] = arr[l_ind];
        l_ind++;
      }
      else if(arr[l_ind] >= arr[r_ind])
      {
        Mass[i] = arr[r_ind];
        r_ind++;
      }
      
    }
    for(int i = *begin; i < *end; i++)
      {
        arr[i] = Mass[i];
      }
    
  }
    //cout << "left: " << left << endl;
    //cout << "right: " << right <<endl;
  
}






int main() {
  //int a[5] = {0,3,2,9,6};
  int a[7] = {5, 4, 7, 2, 8, 3, 6};
  int N = 7;
  //MASSIVE();
  //cout << endl;
  //Сортировка пузырьком
  //bubble_sort(a);
  
  
  //Сортировка выбором
  //sort_choose(a);


  //Сортировка вставками
  //sort_insert(a);

  //Сортировка слиянием, сделать функцию
 /* int begin = 0;
  int *ptr_beg = &begin;
  int end = N;
  int *ptr_end = &end;
  
*/
  //merger_sort(a, ptr_beg, ptr_end);
  
  //Быстрая сортировка
  int begin = 0;
  int *ptr_beg = &begin;
  int end = N-1;
  int *ptr_end = &end;
  quick_sort(a, ptr_beg, ptr_end);

  
  for(int i = 0;i < N;i++){
    cout << a[i] << " ";
  }
}





/*
void increment(int*);

int main()
{
    int n = 10;
    increment(&n);
    cout << "main function: " << n << endl;
}
void increment(int *x)
{
    (*x)++; // получаем значение по адресу в x и увеличиваем его на 1
    cout << "increment function: " << *x << endl;
  
}*/