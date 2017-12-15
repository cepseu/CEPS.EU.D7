// Retina shizzle (we assume querySelector is available)
if (window.devicePixelRatio > 1) {
  // Set default scale to 0.5
  document.querySelector("meta[name=viewport]").setAttribute('content', 'width=device-width; initial-scale=0.5;');
}