#include <vector>
#include <string>
class node{
    public:
    float sigmoid(float numToBeSigmoidified){
        return (1/(1 + exp(-numToBeSigmoidified)));
    }
    float calculateOut(int numOfInputs, std::vector<float> inputs, std::vector<float> wieghts, float bias, std::string typeOfNode){
        float out = 0;
        if(typeOfNode == "binary"){
            for(int i=0; i<numOfInputs; i++){
                out = out + (inputs[i]*wieghts[i]) + bias;
            }
            if((double)out > (double)bias){
                return (float)1;
            }
            else{
                return (float)0;
            }
        }
        else if(typeOfNode == "sigmoid"){
            for(int i=0; i<numOfInputs; i++){
                out = out + (inputs[i]*wieghts[i]) + bias;
            }
            return sigmoid(out);
        }
        else if(typeOfNode == "indentity"){
            for(int i=0; i<numOfInputs; i++){
                out = out + (inputs[i]*wieghts[i]) + bias;
            }
            return out;
        }
    }
};