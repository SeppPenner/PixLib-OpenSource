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
//  PxCollectionViewCell.h
//  PxUIKit
//
//  Created by Jonathan Cichon on 31.01.14.
//  Copyright (c) 2014 pixelflut GmbH. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    PxCellPositionMiddle    = 0,
    PxCellPositionTop       = 1<<0,
    PxCellPositionBottom    = 1<<1,
    PxCellPositionFirst     = 1<<3,
    PxCellPositionLast      = 1<<4,
    PxCellPositionSingle    = 1<<5,
} PxCellPosition;

@interface PxCollectionViewCell : UICollectionViewCell
@property(nonatomic, weak) UICollectionView *collectionView;
@property(nonatomic, assign) id delegate;
@property(nonatomic, strong) id data;
@property(nonatomic, assign, readonly) PxCellPosition cellPosition;

- (void)setData:(id)data setUI:(BOOL)setUI;

- (PxCellPosition)cellPosition;
- (BOOL)hasPosition:(PxCellPosition)position;

@end

@interface PxCollectionViewCell (SubclassingHooks)

+ (CGSize)sizeWithData:(id)data reuseIdentifier:(NSString *)reuseIdentifier collectionView:(UICollectionView *)collectionView;

- (void)buildUI;
- (void)setUI;
- (void)didBeginInteractiveMovement;
- (void)didEndInteractiveMovement;

@end


static inline BOOL PxCellHasPosition(NSString *reuseIdentifier, PxCellPosition position) {
    NSInteger identifier = [reuseIdentifier integerValue];
    return (identifier & position || identifier == position);
}
