#include "Network_Base.h"



Network_Base::Network_Base(size_t dz, size_t iz, size_t oz, unique_ptr<float[]> &data_ref) :
	data_size(dz), input_size(iz), output_size(oz)
{
	data.reset(data_ref.get()); 

	if (data_size - output_size == input_size) {  //if data size and input layer are the same size each neuron has just one input
		for (int i = 0; i < input_size; i++) {   //feed all Neurons in layer 1
			input_layer[i].new_input(data[i], 1, true);
			data2[i] = input_layer[i].output_y();
		}
	}
	else { 
		for (int i = 0; i < input_size; i++) { 
			input_layer[i].new_input(data, input_size); 
			data2[i] = input_layer[i].output_y();
		}
	}

	for (int i = 0; i < output_size; i++) { //feed the neurons in output level
		output_layer[i].new_input(data2, input_size);
		output_layer[i].show();
		output_data[i] = output_layer[i].output_y();
	}

	//Lernen

	while (output_layer[0].adjust_weights(data[data_size - 1], input_size) > 5.28419e-06) {	};
	cout << "Found solution" << output_layer[0].output_y() << endl;

}


Network_Base::~Network_Base()
{
	data.release();
	data2.release();
	output_data.release();
	input_layer.release();
	output_layer.release();
}
