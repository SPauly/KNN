#pragma once
#include "neuron.h"
#include <memory>
#include <iostream>

using namespace std;

class Network_Base
{
	//Network configuration
	size_t data_size; // size of data
	size_t input_size; // how many input neurons
	//size_t hidden_length;
	size_t output_size; // how many output neurons

	unique_ptr<float[]> data{ (make_unique<float[]>(data_size)) }; //to hold the input data
	unique_ptr<float[]> data2{ (make_unique<float[]>(input_size)) }; //hold the output of the first layer
	unique_ptr<float[]> output_data{ (make_unique<float[]>(output_size)) }; // hold the output of output layer

	unique_ptr<Neuron[]> input_layer{ (make_unique<Neuron[]>(input_size)) };
	//unique_ptr<Neuron[]> hidden_layer{ (make_unique<Neuron[]>(hidden_length)) };
	unique_ptr<Neuron[]> output_layer{ (make_unique<Neuron[]>(output_size)) };

public:
	Network_Base(size_t, size_t, size_t, unique_ptr<float[]> &); //data_size, input_size, output_size, data
	~Network_Base();
};

