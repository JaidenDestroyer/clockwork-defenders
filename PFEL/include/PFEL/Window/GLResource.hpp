#ifndef PFEL_GLRESOURCE_HPP
#define PFEL_GLRESOURCE_HPP

// Headers
#include <PFEL/Config.hpp>


namespace pfel
{
	typedef void(*ContextDestroyCallback)(void*);

	// Base class for classes requiring an OpenGL context (INTERNAL USE ONLY)
	class GLResource
	{
		protected:
			// constructor
			GLResource();

			// destructor
			~GLResource();

			/**
			 * Register a function to be called when a context is destroyed
			 *
			 * Used internally to properly clean up OpenGL resources that
			 * cannot be shared between contexts.
			 */
			static void registerContextDestroyCallback(ContextDestroyCallback callback, void* arg);

			// RAII helper class to temporarily lock an available context
			class TransientContextLock
			{
				public:
					TransientContextLock();
					~TransientContextLock();
			}

	}
} // namespace pfel

#endif // PFEL_GLCONTEXT_HPP