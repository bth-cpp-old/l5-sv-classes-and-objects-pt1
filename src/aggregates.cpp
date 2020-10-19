struct Vec3f { float x, y, z; };
struct Box { Vec3f min, max; };

int main(){
	Box myBox = { {1.0f, 2.0f, 3.0f}, {2.0f, 3.0f, 4.0f} };
}
