/**
 * @input A : Read only ( DON'T MODIFY ) 2D integer array
 * @input n11 : Integer array's ( A ) rows
 * @input n12 : Integer array's ( A ) columns
 *
 * @Output Integer array. You need to malloc memory, and fill the length in len1
 */
int* spiralOrder(const int** A, int n11, int n12, int *len1) {

      int *res = (int *)malloc(sizeof(int) * (n11 * n12));
      int T = 0; //Top
      int B = n11 - 1; //Bottom
      int L = 0; // Left
      int R = n12 - 1; // Right
      int dir = 0; //direction
      int i = 0;
      int k = 0;
      *len1 = n11 * n12;

      while( T<=B && L<=R){
          if(dir==0){
              for(i=L ; i<=R  ; i++,k++){
                  res[k] = A[T][i];
                                }
                T++;
                dir = 1;
            }
          else if(dir==1){
              for(i=T ; i<=B ;i++,k++){
                  res[k] =  A[i][R];
              }
              R--;
              dir = 2;
          }
          else if(dir==2){
              for(i=R; i>=L ; i--,k++){
                  res[k] =  A[B][i];
              }
              B--;
              dir = 3;
          }
          else if(dir==3){
              for(i=B ; i >= T ; i--,k++){
                  res[k] =  A[i][L];
              }
              L++;
              dir = 0;
          }
      }
      return res;

}
