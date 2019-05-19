#ifndef PFEL_GLCONTEXT_HPP
#define PFEL_GLCONTEXT_HPP

// Headers
#include <PFEL/Config.hpp>
#include <PFEL/GLResource.hpp>


namespace pfel
{
	namespace priv 
	{
		// Abstract class that represents a OpenGL context
		class GLContext
		{
			public:
				/**
				 * Perform resource initialization
				 *
				 * called every time an OpenGL resoure is created.
				 * When the first resource is initialized, it makes
				 * sure that everything is ready for the contexts to
				 * work properly. 
				 */
				static void initResource();

				/**
				 * Perform resource cleanup
				 *
				 * called every time an OpenGL resoure is destroyed.
				 * When the last resource is destroyed, it makes
				 * sure that everything created by initResource()
				 * is properly released. 
				 */
				static void cleanupResource();

				/**
			 	 * Register a function to be called when a context is destroyed
				 *
				 * Used internally to properly clean up OpenGL resources that
				 * cannot be shared between contexts.
				 */
				static void registerContextDestroyCallback(ContextDestroyCallback callback, void* arg);

				// Acquires a context for short-term use on the current thread
				static void acquireTransientContext();

				// Releases a context after short-term use on the current thread
				static void releaseTransientContext();

				/**
				 * Create a new context, not associated to a window
				 *
				 * called every time an OpenGL resoure is destroyed.
				 * When the last resource is destroyed, it makes
				 * sure that everything created by initResource()
				 * is properly released. 
				 */
				static GLContext* create();
				static GLContext* create();
				static GLContext* create();
		}
	}
} 

#endif // PFEL_GLCONTEXT_HPP