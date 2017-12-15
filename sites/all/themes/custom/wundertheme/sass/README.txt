FOLDER STRUCTURE
---------------------------------------------------------

base -> logic
Contains all your global functions, mixins, extendables, variables and the normalize. Is loaded first in the stylesheet.

base -> color.scss
Gather all your colors in this file for easy maintainability.

base -> layout.scss
Set up your grid here and determine the basic layout behavior.

base -> design.scss
All your global, non-reusable theming goes here: header, footer, breadcrumb, ...

base -> typography.scss
Collect all your typography stuff in this file.

features
Create a file for each feature. For small projects, one file for all features can work as well.

styles
Create a file for each style. For small projects, one file for all styles can work as well


WHEN STARTING A NEW PROJECT ...
---------------------------------------------------------

1. Set your base font settings (base -> typography.scss)
2. Set up your grid & breakpoints (base -> layout.scss)
3. Start with the basic layout (base -> layout.scss)
4. Add the general project colors (base -> color.scss)
5. Add the default theming for header, footer, breadcrumb, links, ... (base -> design.scss)
6. Start theming the features (features -> [feature-name].scss)
7. When certain styles occur and are used more than once, absctract them into a style (styles -> stylename.scss)
8. Keep your code maintainable!


WHEN THROWN IN TO THIS PROJECT ...
---------------------------------------------------------
- Determine the nature of the changes

  1. Design elements (header, footer, breadcrumb, ..)
     : look in base -> design.scss
  2. Feature
     : look in features -> features.scss
  3. Style
     : look in styles -> styles.scss
     
- Avoid changing styles
- If you are changing a style, be sure to check wherever the style is used
- Be aware of the consequences when you change
    colors
    variables
    base font settings
    
GOING TO PRODUCTION
---------------------------------------------------------
If you are going to production with this theme run following command to minifie and clean up the css output

compass compile -e production --force






