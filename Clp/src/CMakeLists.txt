file(
	GLOB
	CLP_SRC_HEADER
	*.hpp
	*.h
)
file(
	GLOB
	CLP_SRC_CPP
	*.cpp
)


file(
     GLOB
     REMOVE_CPP
     ClpCholeskyMumps.cpp
     ClpCholeskyUfl.cpp
     ClpCholeskyWssmp.cpp
     ClpCholeskyWssmpKKT.cpp
     *Abc*.cpp
)   

file(
     GLOB
    REMOVE_HEADER
     ClpCholeskyMumps.hpp
     ClpCholeskyUfl.hpp
     ClpCholeskyWssmp.hpp
     ClpCholeskyWssmpKKT.hpp 
     *Abc*.hpp
     *Abc*.h
)   

list(REMOVE_ITEM CLP_SRC_HEADER ${REMOVE_HEADER})
list(REMOVE_ITEM CLP_SRC_CPP ${REMOVE_CPP})

ADD_LIBRARY(Clp STATIC ${CLP_SRC_HEADER} ${CLP_SRC_CPP})
target_link_libraries(Clp PUBLIC CoinUtils)
INSTALL(TARGETS Clp DESTINATION lib)

add_subdirectory(OsiClp)


