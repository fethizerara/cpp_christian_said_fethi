project("cpp")

add_executable(main main.cpp Interfaces/Fonctionactivation.h Interfaces/Image.h Sources/Image.cpp Interfaces/Input.h Interfaces/Iris.h Sources/Iris.cpp Interfaces/Perceptron.h Sources/Perceptron.cpp Interfaces/Sigmoide.h Sources/Sigmoide.cpp Interfaces/Tanh.h Sources/Tanh.cpp Sources/NN1.cpp Interfaces/NN1.h Interfaces/Apprentissage.h Sources/Perceptron_cache.cpp Interfaces/Perceptron_cache.h Interfaces/Input_intermediaire.h Sources/Input_intermediaire.cpp Interfaces/NN2.h Sources/NN2.cpp
        )