#ifndef TH_GENERIC_FILE
#define TH_GENERIC_FILE "generic/tensor.h"
#else



typedef struct THMKLTensor
{
  THTensor *tensor;   
  long workspace[2]; 
  char freeFlag;
  int mklStorage;  //0:storage buffer allocated by THTensor, 1:storage buffer allocated by mklnn
  long mkldnnLayout;
  char flagBackup;
  size_t * size;
} THMKLTensor;

#define MKL_TENSOR_FLAG  32

void TH_MKL_(copyFromTH)(THMKLTensor * pTensor, THTensor * src);
void TH_MKL_(copyBacktoTH)(THTensor * pTensor, THMKLTensor * src);
void TH_MKL_(TH2MKL)(THMKLTensor * pTensor, THTensor * src);
void TH_MKL_(MKL2TH)(THTensor * pTensor, THMKLTensor * src);
void TH_MKL_(resize4d)(THMKLTensor *self, size_t size0, size_t size1, size_t size2, size_t size3);
void TH_MKL_(resizeAs)(THMKLTensor *self, THMKLTensor *src);
real* TH_MKL_(data)(THMKLTensor *self);
int TH_MKL_(nElement)(const THMKLTensor *self);
void TH_MKL_(free)(THMKLTensor *self);
/*
dnnError_t  TH_MKL_(createWorkspace)(THMKLTensor* pTensor);
dnnError_t MKLDNN_(dnnLayoutCreate)(dnnLayout_t *pLayout, size_t dimension, const size_t size[], const size_t strides[]);
int MKLDNN_(dnnLayoutCompare)(const dnnLayout_t l1, const dnnLayout_t l2);       
dnnError_t MKLDNN_(dnnConversionCreate)(dnnPrimitive_t* pConversion, const dnnLayout_t from, const dnnLayout_t to);
dnnError_t MKLDNN_(dnnAllocateBuffer)(void **pPtr, dnnLayout_t layout);
*/
#endif
