#include "neuron.h"

Neuron::Neuron() {};

Neuron::Neuron(unique_ptr<float[]> &input, size_t& in) : input_length(in), weights(make_unique<float[]>(input_length)) {  //When using sigmoid activation

	x.reset(input.get());

	for (int i = 0; i < input_length; i++) { //initialize weights
		weights[i] = RAND;
	}

	output(); // output
};

//Neuron::Neuron(unique_ptr<float[]> &input, size_t& in, bool no_weights) : input_length(in){  //When using sigmoid activation no weights
//
//	in_xi.reset(input.get());
//
//    output(no_weights); // output
//};

//Neuron::Neuron(unique_ptr<float[]> &input, unique_ptr<float[]> &we, size_t& in, float act) : input_length(in), custom_act(act), //When using a custom activation + weights
//weights(make_unique<float[]>(input_length)) {
//
//	in_xi.reset(input.get());
//	weights.reset(we.get());
//
//	output(); // output
//};

Neuron::~Neuron() {
	x.release();
	weights.release();
	wtemp.release();
}

float Neuron::fnet() {  //Netzeingabefunktion -> Dot Product
	float fynet = 0.0f;
	for (int i = 0; i < input_length; i++) {
		fynet += x[i] * weights[i];
	}
	return fynet;
}

float Neuron::factivity(float ynet) { //Aktivierungsfunktion (sigmoid)
	return 1 / (1 + exp(-10 * (ynet - 0.5)));
}

//float Neuron::factivity(float cust) { //Aktivierungsfunktion custom1
//	return activity = ynet > cust ? 1.0f : 0.0f;
//}

float Neuron::first_act() {
	return x[0] / 10.0f;
}

float Neuron::new_input(unique_ptr<float[]> &input, size_t& in) {
	x.reset(input.get());
	weights = make_unique<float[]>(in);
	wtemp = make_unique<float[]>(in);
	input_length = in;

	for (int i = 0; i < input_length; i++) { //initialize weights
		weights[i] = RAND;
	}

	return output(); // output
}

float Neuron::new_input(float input, size_t in) {
	input_length = in;
	x = make_unique<float[]>(in);
	weights = make_unique<float[]>(in);
	wtemp = make_unique<float[]>(in);
	x[0] = input;

	weights[0] = RAND;

	return output(); // output
}

float Neuron::new_input(float input, size_t in, bool now) {
	input_length = in;
	x = make_unique<float[]>(in);
	x[0] = input;

	return output(true); // output
}

void Neuron::show() {
	for (int i = 0; i < input_length; i++) {
		cout << "x" << i + 1 << ": " << x[i] << "  w" << i + 1 << ": " << weights[i] << endl;
	}
	cout << "output: " << y << endl;
	cout << endl;
}

float Neuron::adjust_weights(float y_soll, size_t input_size) {

	for (int i = 0; i < input_size; i++) {
		wtemp[i] = weights[i] + 0.7f * x[i] * ((y_soll / 10) - y);
	}

	for (int i = 0; i < input_size; i++) {
		weights[i] = wtemp[i];
	}

	output();

	return (y_soll / 10) - y;

}
