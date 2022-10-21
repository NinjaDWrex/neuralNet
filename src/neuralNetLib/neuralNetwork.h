#include "layer.h"
#include <vector>
class neuralNetwork{
    public:
    std::vector<float> outputResult(int numOfInputs, std::vector<std::vector<float>> input, std::vector<std::vector<float>> weightConfig, std::vector<std::vector<float>> biasConfig, std::vector<std::string> layerTypesConfig, std::vector<int> numOfNodesConfig, int numOfLayers){
        std::vector<layer*> iteratableObj;
        for(int i = 0; i < numOfLayers; i++){
            layer* layerObjPointer = new layer();
            iteratableObj.push_back(layerObjPointer);
            input[i+1] = layerObjPointer->calcThisLayer(input[i], weightConfig[i], numOfInputs, biasConfig[i], layerTypesConfig[i], numOfNodesConfig[i]);
        }
        for(int i = 0; i < iteratableObj.size(); i++){
            delete iteratableObj[i];
        }
        return input[numOfLayers+1];
    }
};
