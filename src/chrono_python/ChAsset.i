%{

/* Includes the header in the wrapper code */
#include "assets/ChAsset.h"

using namespace chrono;

%}

// Enable shared pointer
%shared_ptr(chrono::ChAsset) 

/* Parse the header file to generate wrappers */
%include "../chrono/assets/ChAsset.h"    


