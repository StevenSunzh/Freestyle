# Freestyle


Pixate Freestyle is a toolkit for styling native mobile applications. It consists of a comprehensive collection of CSS classes that work with the [Pixate Framework](http://www.pixate.com/) to provide an easily customized base of styles for applications. Think of it as Bootstrap for native apps. Currently, it only supports iOS 7. Android support is coming soon.

![My image](https://raw.github.com/Pixate/Freestyle/gh-pages/freestyle_typography.png)
![My image](https://raw.github.com/Pixate/Freestyle/gh-pages/freestyle_form_styles.png)


## Getting started

Getting started with Freestyle is easy. You need to install the [Pixate Framework](http://www.pixate.com), add the Freestyle CSS or Sass files to your project, and apply the Freestyle classes to views and controls in your app. 

### Installing the Pixate Framework

The Pixate Framework lets you style your native iOS applications with stylesheets. If you aren't already familiar with Pixate, check out the [Getting Started](http://www.pixate.com/docs/framework/ios/latest/getting-started/) guide to familiarize yourself with how it works. You can install it in three ways:

* [Download directly from Pixate](http://download.pixate.com/). Freestyle is already packed in this download.
* Install using [CocoaPods](http://cocoapods.org/) (spec name is 'Pixate').
* Clone the Pixate Framework repo  `git clone git@github.com:Pixate/PixateFramework.git`.

You can also clone the [Freestyle repo](https://github.com/Pixate/Freestyle) and use the Showcase app as a starter app, which already has the latest release of Pixate installed. Note that the Showcase uses the Freestyle CSS file, so you can try it out without installing Sass. If you want to play around with variables and such, you'll need to follow the instructions below for compiling the Sass files.

Once you have the framework, follow the [Getting Started](http://www.pixate.com/docs/framework/ios/latest/getting-started/) guide to set up the framework in your application. **Note that you will need Pixate 2.0.1 or greater for Freestyle to work properly**. Also, the Pixate Framework now includes Freestyle, so you won't need to download Freestyle separately.

### Get Freestyle

You can grab Freestyle two ways:

* [Download the latest release](https://github.com/Pixate/Freestyle/archive/master.zip).
* Clone this repo `git clone git@github.com:Pixate/Freestyle.git`.

Note the Freestyle currently only contains styles for apps targeting iOS 7. You can certainly add your own styles for iOS 6.

### Add Freestyle to your app

Once you've [downloaded](http://download.pixate.com/) and [installed](http://www.pixate.com/docs/framework/ios/latest/getting-started/) Pixate and downloaded Freestyle, you have two options to add Freestyle to your project:

* Add the default.css file from the Freestyle repo to your project. This contains all of the styles, but will be harder to customize as it is not modular. 
* Add the [Sass](http://sass-lang.com) files to your project. You will need to set up the Sass precompiler - see the 'Compiling Sass' section below. This option makes it a lot easier to customize the styles, since it's completely modular. 

Once the CSS or SCSS files are added, you can apply the classes to any relevant view or control by adding a `styleClass` runtime attribute in Interface Builder to the view or control, or importing `Pixate/Pixate.h` in your view controller and setting the `styleClass` property (e.g. `myButton.styleClass = @"button small";`. The Pixate [Getting Started](http://www.pixate.com/docs/framework/ios/latest/getting-started/#using_css) guide has more details on setting classes.

### What's included in the toolkit

```
Freestyle/
├── css/
│   └── default.css
├── scss/
│   ├── default.scss
│   ├── base.scss
│   ├── forms.scss
│   ├── type.scss
│   └── variables.scss
└── PixateFreestyleShowcase/
    ├── PixateFreestyleShowcase/
    ├── PixateFreestyleShowcaseTests
    └── PixateFreestyleShowcase.xcodeproj
```
        

## Compiling Sass 

Included in Freestyle are several [Sass](http://sass-lang.com) files that, once compiled, generate the Freestyle CSS that will be used by the Pixate Framework. Sass allows Freestyle to be modular. You can modify variables to theme the default styles, or edit any part of the Sass to your heart's content.

You can simply grab the compiled CSS file from this repo and add it to your project (see [Getting Started](http://www.pixate.com/docs/framework/ios/latest/getting-started/)), or you can follow these simple steps to compile the .scss files. Once you've installed Pixate and added the Freestyle Sass files to your application, do the following:

* Install [Sass](http://sass-lang.com/install) - this requires Ruby, which you should already have if you're running OS X.
* If you already added the Freestyle default.css file to your project, remove it (it will be replaced by the compiled Sass files).
* Add all of the files in Freestyle/scss to your project in Xcode.
* In XCode, click on your project in the Project Navigator.  
* Click on the `Build Phases` tab.
* From the top menu under `Editor`, select `Add Build Phase`, then `Add Build Script Run Phase`.
* In the new Run Script field enter: 

```
source /Users/${USER}/.rvm/environments/default
${GEM_HOME}/bin/sass ${TARGET_BUILD_DIR}/${CONTENTS_FOLDER_PATH}/default.scss ${TARGET_BUILD_DIR}/${CONTENTS_FOLDER_PATH}/default.css
```

* Do not put anything under `Input Files` or `Output Files`

Now, when you build your project, the Sass files should be compiled into a default.css file that will be used by the Pixate Framework. 

## Documentation

We will be building docs for Freestyle once the beta stabilizes. In the meantime, please submit any questions on the [Issues page](https://github.com/Pixate/Freestyle/issues).  

The Showcase app is meant to serve as an example application using all of the styles, as well as a reference app for starting a new project or creating themes. We used Storyboards in the app to make it easy to play with, but we had to write a few lines of code to make certain things work.

To enable static scroll views (used for the typography and form pages) that are taller than the device resolution, we added the following viewDidLayoutSubviews method to our view controllers:

```
- (void)viewDidLayoutSubviews {
    [super viewDidLayoutSubviews];
    
    // enable scrolling in the scrollView
    [self.scrollView layoutIfNeeded];
    self.scrollView.contentSize = self.contentView.bounds.size ;
    
    // place the scrollView in the proper position
    CGRect screenBound = [[UIScreen mainScreen] bounds];
    CGFloat width = screenBound.size.width;
    CGFloat tabBarHeight = [[self.tabBarController tabBar] frame].size.height;
    CGFloat navBarHeight = [[self.navigationController navigationBar] frame].size.height;
    CGFloat height = screenBound.size.height - tabBarHeight - navBarHeight;
    self.scrollView.frame = CGRectMake(0, 0, width, height);
}
```

Additionally, to set the height of these scroll views, we changed the `Size` setting to `Freeform` under Simulated Metrics in the Attributes inspector for the view controller. 

We also needed code in other places to generate our table view, collection view, and our icons. 

## Feedback and Bugs

We are releasing Freestyle in beta because we really want to hear feedback or feature requests. What would an ideal mobile app toolkit look like for you? [Please open a new issue](https://github.com/Pixate/Freestyle/issues/new). 

Before opening a new issue, please search existing issues.

## Contributing

We currently are not accepting any pull requests, as we want to get Freestyle 1.0 officially out first. In the future we'll welcome contributions with open arms, including new themes and samples from the community.

