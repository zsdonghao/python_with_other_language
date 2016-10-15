/* example.i */
%module example
// simple struct
// %{
//      struct dh
//      {
//          int x;
//          int y;
//          void (*func)(int);
//      };
//      extern struct dh DH;
// %}
//
// struct dh
// {
//     int x;
//     int y;
//     void (*func)(int);
// };
// extern struct dh DH;

//
// extern void triple_fn(int a);

// struct with method
// %module mymodule
%{
#include "example.h"
%}

%include "example.h"          // Just grab original C header file
%extend Vector {             // Attach these functions to struct Vector
	Vector(double x, double y, double z) {
		Vector *v;
		v = (Vector *) malloc(sizeof(Vector));
		v->x = x;
		v->y = y;
		v->z = z;
		return v;
	}
	~Vector() {
		free($self);
	}
	double magnitude() {
		return sqrt($self->x*$self->x+$self->y*$self->y+$self->z*$self->z);
	}
  double sum() {
    return $self->x + $self->y + $self->z;
  }
  double distance(double x1, double y1, double z1) {
    return sqrt(($self->x-x1)*($self->x-x1) + ($self->y-y1)*($self->y-y1) + ($self->z-z1)*($self->z-z1));
  }
	void printinfo() {
		printf("Vector [%g, %g, %g]\n", $self->x,$self->y,$self->z);
	}
};
