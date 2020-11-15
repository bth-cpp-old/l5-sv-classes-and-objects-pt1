#include <iostream>

class MphConverter {
  private:
	static const float mphToKmhFactor;

  public:
	static float toKmh(float mph){
		return mph*mphToKmhFactor;
	}
};

const float MphConverter::mphToKmhFactor = 1.60934;

int main(){
	std::cout<<"60 mph is "<<MphConverter::toKmh(60)<<" Kmh";
}