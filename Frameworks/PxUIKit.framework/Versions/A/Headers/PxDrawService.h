/*
 * Copyright (c) 2013 pixelflut GmbH, http://pixelflut.net
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 */

//
//  PxDrawService.h
//  PxUIKit
//
//  Created by Jonathan Cichon on 31.01.14.
//  Copyright (c) 2014 pixelflut GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <PxCore/PxCore.h>

@interface PxDrawService : NSObject
PxSingleton(defaultService)

#pragma mark - Basic Methods
/** Creates a new image with given size with the image content generated by calling the block with user-defined drawing operations.
 
 The resulting image is saved to the file system and retrieved everytime the same reuseidentifier (+ size) is given.
 @param size The size of the resulting image.
 @param reuseIdentifier A string identifying the image object to be reused. If this parameter is **nil** no caching can pe applied.
 @param drawBlock The block with the user-defined drawing operations.
 @return The image.
 @see imageWithSize:reuseIdentifier:drawingBlock:opaque:
 */
- (UIImage *)imageWithSize:(CGSize)size reuseIdentifier:(NSString *)reuseIdentifier drawingBlock:(void (^)(CGContextRef ctx))drawBlock;

/** Creates a new, possible opaque, image with given size with the image content generated by calling the block with user-defined drawing operations.
 
 The resulting image is saved to the file system and retrieved everytime the same reuseidentifier (+ size) is given.
 @param size The size of the resulting image.
 @param reuseIdentifier A string identifying the image object to be reused. If this parameter is **nil** no caching can pe applied.
 @param drawBlock The block with the user-defined drawing operations.
 @param opaque Either or not the resulting image is opaque.
 @return The image.
 @see imageWithSize:reuseIdentifier:drawingBlock:
 */
- (UIImage *)imageWithSize:(CGSize)size reuseIdentifier:(NSString *)reuseIdentifier drawingBlock:(void (^)(CGContextRef ctx))drawBlock opaque:(BOOL)opaque;

/** Calls the given block with the current graphics context.
 @param drawBlock The block with the user-defined drawing operations.
 */
- (void)drawBlock:(void (^)(CGContextRef ctx))drawBlock;

@end
