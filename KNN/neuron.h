#pragma once
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

#define RAND		((float)rand()/(RAND_MAX+1))
#define NUMERIC

class Neuron {
	//inputs
	unique_ptr<float[]> x;
	//weights
	unique_ptr<float[]> weights;
	unique_ptr<float[]> wtemp;
	//output
	float y;
	//input length
	size_t input_length;


	float fnet(); //Dot Product

	float factivity(float); //Aktivierungsfunktion (sigmoid)

	float first_act(); //devides the input by 100 -> it's between 1 and 0


#ifndef NUMERIC
	float output() { //Binary output
		return y = factivity(fnet()) > 0.5 ? 1.0f : 0.0f;
	}
	float output(bool) {
		return y = first_act() > 0.5 ? 1.0f : 0.0f;
	}
#endif // !NUMERIC

#ifdef NUMERIC
	float output() { //Numeric output
		return y = factivity(fnet());
	}
	float output(bool) {
		return y = first_act();
	}
#endif // NUMERIC

public:
	Neuron();
	Neuron(unique_ptr<float[]> &input, size_t & in); //When using sigmoid activation
	//Neuron(unique_ptr<float[]> &input, size_t & in, bool); //When using sigmoid activation (for first layer using no weights
	//Neuron(unique_ptr<float[]> &input, unique_ptr<float[]> &we, size_t& in, float act); //When using a custom activation + weights
	~Neuron(); 

	float new_input(unique_ptr<float[]> &, size_t&);
	float new_input(float, size_t); //When there is just one input
	float new_input(float, size_t, bool); //When there is just one input -> devides by 100 so its between 1 and 0

	float output_y() {
		return y;
	};

	void show(); 
	float adjust_weights(float, size_t);
};
