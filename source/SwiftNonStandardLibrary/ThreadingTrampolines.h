//
//  ThreadingTrampolines.h
//  Swift Non-Standard Library
//
//  Created by Russ Bishop
//  http://github.com/xenadu/SwiftNonStandardLibrary
//
//  MIT licensed; see LICENSE for more information
//

@import Darwin;
#import <Foundation/Foundation.h>


void oss_pthread_cleanupKey(void *value);
pthread_key_t oss_pthread_createKey();


/*! Release any context object attached to the queue */
void oss_dispatch_cleanup_queue(void *value);
/*! Register for cleanup on a queue created in Swift since Swift can't handle C function pointers */
void oss_dispatch_set_finalizer_f(dispatch_queue_t queue);


/*!  */
void oss_dispatch_cleanup_specific(void *value);


/*! Work around a Swift bug that prevents retrieving an unmanaged object in some cases */
id oss_void_pointer_to_object_unretained(void *ptr);

//void
//dispatch_queue_set_specific(dispatch_queue_t queue, const void *key,
//                            void *context, dispatch_function_t destructor);


//Note: Swift won't import our C functions unless we fake it with a .h and .m, at least for now.
//      This may just be a defect in the way I've set things up, or a compiler bug of some kind.
