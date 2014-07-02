#include <stdio.h>
#include <sys/stat.h>
void decrypt (unsigned int* v, unsigned int* k);
int main(){
 
 unsigned int k[4]={0};
 unsigned int v[2]={0};
 while(1){
 scanf("%x %x", &v[0], &v[1]);
  k[0]= 0xf71850f5;
  k[1]= 0x5db8544a;
  k[2]= 0xbf5ecf69;
  k[3]= 0xcb93ef85;
  //k[0]=0x85ef93cb,k[1]=0x69cf5ebf, k[2]=0x4a54b85d, k[3]=0xf55018f7;
  decrypt(v,k);
  printf("%x    %x\n", v[0],v[1]);
 }
 return 0;
}
void decrypt (unsigned int* v, unsigned int* k) {
    unsigned int v0=v[0], v1=v[1], sum=0xC6EF3720, i;  /* set up */
    unsigned int delta=0xb979379e;          //0x9e3779b9           /* a key schedule constant */
    unsigned int k0=k[0], k1=k[1], k2=k[2], k3=k[3];   /* cache key */
    for (i=0; i<32; i++) {                         /* basic cycle start */
        v1 -= ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
        v0 -= ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        sum -= delta;
    }                                              /* end cycle */
    v[0]=v0; v[1]=v1;
}
