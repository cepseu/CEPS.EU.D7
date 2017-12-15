if (typeof(CKEDITOR) !== 'undefined') {

  CKEDITOR.stylesSet.add( 'drupal',
  [

    {
      name: 'Knop',
      element: 'p',
      attributes: {
        'class': 'link-button'
      }
    },
    {
      name: 'Lees meer link',
      element: 'p',
      attributes: {
        'class': 'readmore-link'
      }
    },

    // Object Styles
    {
      name : 'Afbeelding Links',
      element : 'img',
      attributes :
      {
        'class' : 'img-float-left'
      }
    },
    {
      name : 'Afbeelding Rechts',
      element : 'img',
      attributes :
      {
        'class' : 'img-float-right'
      }
    }

  ]);
}
