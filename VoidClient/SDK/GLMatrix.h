#pragma once

struct GLMatrix {
public:
	float matrix[16];
	float matrix_nest[4][4]; // nested because im compensating :slight_smile: (Just as hard as all the other clientndevelopers ovs)
};