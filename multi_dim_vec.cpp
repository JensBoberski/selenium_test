#include<iostream>
#include<vector>

int main (){
  // size of vectors: Instruments.size, TsSlots, 2, events
  // x[instrument][tsSlot][value or di(value)][eventNumber]
  // this stores a fixed amount of events

  unsigned dim1=3000;
  unsigned dim2=100;
  unsigned dim3=2;
  unsigned dim4=20;


// method 1
  std::vector< std::vector< std::vector< std::vector<float> > > > test4; //3000x100x2xn

  //first dimension
  test4.resize(dim1);

  //second dimension
  for (unsigned ii=0; ii<test4.size(); ++ii){
      test4[ii].resize(dim2);
  }

  //third dimension
  for (unsigned ii=0; ii<test4.size(); ++ii){
    for(unsigned jj=0; jj<test4[ii].size(); ++jj){
      test4[ii][jj].resize(dim3);
    }
  }

  //fourth dimension
  for (unsigned ii=0; ii<test4.size(); ++ii){
    for(unsigned jj=0; jj<test4[ii].size(); ++jj){
      for(unsigned kk=0; kk<test4[ii][jj].size(); ++kk){
        test4[ii][jj][kk].resize(dim4);
      }
    }
  }
  test4[100][99][0][12]=4;
  std::cout << test4[100][99][0][12] <<std::endl;


//method 2

typedef std::vector<float> vector1D;
typedef std::vector<vector1D> vector2D;
typedef std::vector<vector2D> vector3D;
typedef std::vector<vector3D> vector4D;

vector4D test_c(dim1, vector3D(dim2, vector2D(dim3, vector1D(dim4))));
test_c[2999][99][1][12]=100;
std::cout << test_c[2999][99][1][12] <<std::endl;


//resizing last dimension
vector4D test_d(dim1, vector3D(dim2, vector2D(dim3, vector1D(0))));
test_d[2999][99][1].resize(20);
test_d[2999][99][1][12]=200;
std::cout << test_d[2999][99][1][12] <<std::endl;

// without typedef
std::vector<std::vector<std::vector<std::vector<float> > > >
test_e(dim1, std::vector<std::vector<std::vector<float> > >(dim2, std::vector<std::vector<float> >(dim3, std::vector<float>(dim4))));
test_e[2999][99][1][12]=300;
std::cout << test_e[2999][99][1][12] <<std::endl;


}
