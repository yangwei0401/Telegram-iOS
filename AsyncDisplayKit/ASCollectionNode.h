//
//  ASCollectionNode.h
//  AsyncDisplayKit
//
//  Created by Scott Goodson on 9/5/15.
//  Copyright (c) 2015 Facebook. All rights reserved.
//

#import <AsyncDisplayKit/ASCollectionView.h>

@protocol ASCollectionViewLayoutFacilitatorProtocol;
@protocol ASRangeControllerUpdateRangeProtocol;

NS_ASSUME_NONNULL_BEGIN

/**
 * ASCollectionNode is a node based class that wraps an ASCollectionView. It can be used
 * as a subnode of another node, and provide room for many (great) features and improvements later on.
 */
@interface ASCollectionNode : ASDisplayNode <ASRangeControllerUpdateRangeProtocol>

- (instancetype)initWithCollectionViewLayout:(UICollectionViewLayout *)layout;
- (instancetype)initWithFrame:(CGRect)frame collectionViewLayout:(UICollectionViewLayout *)layout;

@property (weak, nonatomic) id <ASCollectionDelegate>   delegate;
@property (weak, nonatomic) id <ASCollectionDataSource> dataSource;

@property (nonatomic, readonly) ASCollectionView *view;

/**
 * Tuning parameters for a range type in full mode.
 *
 * @param rangeType The range type to get the tuning parameters for.
 *
 * @returns A tuning parameter value for the given range type in full mode.
 *
 * @see ASLayoutRangeMode
 * @see ASLayoutRangeType
 */
- (ASRangeTuningParameters)tuningParametersForRangeType:(ASLayoutRangeType)rangeType;

/**
 * Set the tuning parameters for a range type in full mode.
 *
 * @param tuningParameters The tuning parameters to store for a range type.
 * @param rangeType The range type to set the tuning parameters for.
 *
 * @see ASLayoutRangeMode
 * @see ASLayoutRangeType
 */
- (void)setTuningParameters:(ASRangeTuningParameters)tuningParameters forRangeType:(ASLayoutRangeType)rangeType;

/**
 * Tuning parameters for a range type in the specified mode.
 *
 * @param rangeMode The range mode to get the runing parameters for.
 * @param rangeType The range type to get the tuning parameters for.
 *
 * @returns A tuning parameter value for the given range type in the given mode.
 *
 * @see ASLayoutRangeMode
 * @see ASLayoutRangeType
 */
- (ASRangeTuningParameters)tuningParametersForRangeMode:(ASLayoutRangeMode)rangeMode rangeType:(ASLayoutRangeType)rangeType;

/**
 * Set the tuning parameters for a range type in the specigied mode.
 *
 * @param tuningParameters The tuning parameters to store for a range type.
 * @param rangeMode The range mode to set the runing parameters for.
 * @param rangeType The range type to set the tuning parameters for.
 *
 * @see ASLayoutRangeMode
 * @see ASLayoutRangeType
 */
- (void)setTuningParameters:(ASRangeTuningParameters)tuningParameters forRangeMode:(ASLayoutRangeMode)rangeMode rangeType:(ASLayoutRangeType)rangeType;

/**
 * Reload everything from scratch, destroying the working range and all cached nodes.
 *
 * @param completion block to run on completion of asynchronous loading or nil. If supplied, the block is run on
 * the main thread.
 * @warning This method is substantially more expensive than UICollectionView's version.
 */
- (void)reloadDataWithCompletion:(void (^)())completion;

/**
 * Reload everything from scratch, destroying the working range and all cached nodes.
 *
 * @warning This method is substantially more expensive than UICollectionView's version.
 */
- (void)reloadData;

/**
 * Reload everything from scratch entirely on the main thread, destroying the working range and all cached nodes.
 *
 * @warning This method is substantially more expensive than UICollectionView's version and will block the main thread
 * while all the cells load.
 */
- (void)reloadDataImmediately;

@end

NS_ASSUME_NONNULL_END
