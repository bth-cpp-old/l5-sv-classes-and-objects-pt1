struct Vec3f { float x, y, z; };
struct Box { Vec3f min, max; };

int main(){
	Vec3f myVec{1.0f, 0.0f, 0.0f};
	Box myBox = { {1.0f, 2.0f, 3.0f}, {2.0f, 3.0f, 4.0f} };
}
