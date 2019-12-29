//Einfaches Neuron
#include"neuron.h"
#include"XORNet.h"
#include "Network_Base.h"

using namespace std;

//class devideDataspace {
//	unique_ptr<float[]> data_a{ (make_unique<float[]>(2)) }; 
//	unique_ptr<float[]> weights_a{ (make_unique<float[]>(2)) };
//
//	Neuron A();
//};

int main() {
	//XORNet net(.0f,.0f,1.5f,0.5f);
	//XORNet net1(1.0f, 1.0f, 1.5f, 0.5f);
	//XORNet net2(.0f, 1.0f, 1.5f, 0.5f);
	//XORNet net3(1.0f, .0f, 1.5f, 0.5f);
	unique_ptr<float[]> train_data(make_unique<float[]>(3));
	train_data[0] = 3.0f;
	train_data[1] = 7.0f;
	train_data[2] = 10.0f;
    
	size_t data_size = 3; // size of data
	size_t input_size = 2;// how many input neurons
					   //size_t hidden_length;
	size_t output_size = 1; // how many output neurons
	Network_Base nb(data_size, input_size, output_size, train_data);
	cin.get();
	return 1;
}