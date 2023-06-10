#ifndef NN_H_
#define NN_H_

#include <stddef.h>
#include <stdio.h>

#ifndef NN_MALLOC
#include <stdlib.h>
#define NN_MALLOC malloc
#endif

#ifndef NN_ASSERT
#include <assert.h>
#define NN_ASSERT assert
#endif

typedef struct {
  size_t rows;
  size_t cols;
  float *es;
} Mat;

#define MAT_AT(m, i, j) (m).es[(i)*m.cols + (j)]

Mat mat_alloc(size_t rows, size_t cols);
void mat_dot(Mat dest, Mat a, Mat b);
void mat_sum(Mat dest, Mat a);
void mat_print(Mat m);

#endif



#ifdef NN_IMPLEMENTATION

Mat mat_alloc(size_t rows, size_t cols) {

  Mat m;
  m.rows = rows;
  m.cols = cols;
  m.es = NN_MALLOC(sizeof(*m.es)*rows*cols);
  NN_ASSERT(m.es != NULL);
  return m;
}

void mat_dot(Mat dest, Mat a, Mat b){

  (void) dest;
  (void) a;
  (void) b;
};

void mat_sum(Mat dest, Mat a){

  (void) dest;
  (void) a;
};

void mat_print(Mat m){
  for(size_t i=0; i<m.rows; ++i){
    for(size_t j=0; j<m.cols; ++j){
      printf("%f ", MAT_AT(m, i, j));     
    }
    printf("\n");
  }
 
};

#endif
