/*
 * Copyright (c) 2014 pixelflut GmbH, http://pixelflut.net
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
//  PxMarkupKitSupport.h
//  PxMarkupKit
//
//  Created by Jonathan Cichon on 30.01.14.
//  Copyright (c) 2014 pixelflut GmbH. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    PxContentTypeNone   = 0,
    PxContentTypeCXML   = 1,
    PxContentTypeJSON   = 2,
    PxContentTypeXML    = 3,
    PxContentTypePlain  = 4
} PxContentType;

static inline PxContentType PxContentTypeFromNSString(NSString *string) {
    string = [[string componentsSeparatedByString:@";"] firstObject];
    if ([string isEqualToString:@"text/cxml"] || [string isEqualToString:@"cxml"]) {
        return PxContentTypeCXML;
    } else if ([string isEqualToString:@"text/json"]) {
        return PxContentTypeJSON;
    } else if ([string isEqualToString:@"text/plain"]) {
        return PxContentTypePlain;
    } else if ([string isEqualToString:@"text/xml"] || [string isEqualToString:@"application/xml"]) {
        return PxContentTypeXML;
    }
    return PxContentTypeNone;
}