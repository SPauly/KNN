//#include "XORNet.h"
//
//
//
//XORNet::XORNet(float x1, float x2, float act1, float act2)
//{
//	data[0] = x1;
//	data[1] = x2;
//	weights[0] = 1.0f;
//	weights[1] = 1.0f;
//	Neuron Eingangsschicht{ data, weights, data_size, act1 };
//	data1[0] = x1;
//	data1[1] = Eingangsschicht.output();
//	data1[2] = x2;
//	weights1[0] = 1.0f;
//	weights1[1] = -2.0f;
//	weights1[2] = 1.0f;
//	data_size = 3;
//	Neuron Ausgangsschicht{ data1, weights1, data_size, act2 };
//	Ausgangsschicht.show();
//}
//
//
//XORNet::~XORNet()
//{
//	data.release();
//	weights.release();
//	data1.release();
//	weights1.release();
//}
