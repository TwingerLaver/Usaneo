#ifdef MULTI_RENDERING_HPP
#define MULTI_RENDERING_HPP



template <typename T> 


class TypedArray; 


class MultiRenderingSP
{
public:
	struct Singleton {
		static MultiRenderingSP instance;
	};
};
#endif 