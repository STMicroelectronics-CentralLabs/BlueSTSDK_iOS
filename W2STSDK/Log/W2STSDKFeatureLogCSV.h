//
//  W2STSDKFeatureLogCSV.h
//  W2STApp
//
//  Created by Giovanni Visentini on 22/04/15.
//  Copyright (c) 2015 STMicroelectronics. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "W2STSDKFeature.h"

/**
 * class that implement the W2STSDKFeatureLogDelegate and store the data in a csv
 * file with the same name of the feature.
 * it can be used for logging multiple feature, each feature has is file. the files
 * are keeped open for avoid multiple fopen/fclose.
 * call closeFiles when you stop the logging for avoid to keep open the resources
 *
 * in the log file has the colum:
 *  - NodeName: name of the node that send the data
 *  - RawData: exadecimal version of the raw data used for extract the feature data
 *  a colum for each feature item
 */
@interface W2STSDKFeatureLogCSV : NSObject<W2STSDKFeatureLogDelegate>

/**
 *  create the logger
 *
 *  @return pointer to the logger
 */
-(id)init;

/**
 *  close all the open files
 */
-(void) closeFiles;

/**
 *  get all the csv file in the directory
 *
 *  @return array of NSURL with the created log files
 */
+(NSArray*) getLogFiles;

/**
 *  remove all the file with estension *.csv in the same folter where we save the log files
 */
+(void) removeLogFiles;

@end
