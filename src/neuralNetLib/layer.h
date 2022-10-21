#include "node.h"
#include <vector>
#include <string>
#include <math.h>
class layer{
    public:
    std::vector<float> output;
    std::vector<node*> iteratableObjects;
    std::vector<float> calcThisLayer(std::vector<float> layerIn, std::vector<float> weightValues, int numOfInput, std::vector<float> biases, std::string typeOfNeuron, int sizeOfLayer){
        for(int i = 0; i < sizeOfLayer; i++){
            node* nodeObjectPointer = new node();
            iteratableObjects.push_back(nodeObjectPointer);
            output.push_back(nodeObjectPointer->calculateOut(numOfInput, layerIn, weightValues, biases[i], typeOfNeuron));
        }
        for(int i = 0; i < iteratableObjects.size(); i++){
            delete iteratableObjects[i];
        }
        return output;
    }
};